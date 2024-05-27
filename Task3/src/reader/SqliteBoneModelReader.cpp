#include "SqliteBoneModelReader.h"
#include "sqlitereaderexception.h"
#include <memory>

static const char * ReadPointsSql = "SELECT * FROM point ORDER BY id ASC";
static const char * ReadEdgesSql = "SELECT * FROM edge";

SqliteBoneModelReader::SqliteBoneModelReader(const char *filename) : _fname(filename), _db(nullptr), _centerStrategy(std::make_shared<ClassicCenterStrategy>()) { }

SqliteBoneModelReader::~SqliteBoneModelReader() { 
    if (IsOpen())
        Close();
}

bool SqliteBoneModelReader::IsOpen() {
    return _db != nullptr;
}


void SqliteBoneModelReader::Open() {
    int rc = sqlite3_open(_fname, &_db);
    if (rc!= SQLITE_OK) {
        time_t now = time(nullptr);
        throw SqliteNoFileException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
}

void SqliteBoneModelReader::Close() {
    sqlite3_close(_db);
    _db = nullptr;
}


static int ReadPointsCallback (void* data, int argc, char** argv, char **colNames) {
    (void) colNames;
    auto points = static_cast<std::vector<Point>*>(data);
    if (argc!= 4) {
        return 1;
    }
    double x = std::atof(argv[1]);
    double y = std::atof(argv[2]);
    double z = std::atof(argv[3]);
    points->push_back(Point(x, y, z));
    return 0;
}

std::vector<Point> SqliteBoneModelReader::ReadPoints() {
    if (!IsOpen()) {
        return std::vector<Point>();
    }

    std::vector<Point> points;

    int rc = sqlite3_exec(_db, ReadPointsSql, ReadPointsCallback, &points, nullptr);

    if (rc!= SQLITE_OK) {
        
        time_t now = time(nullptr);
        throw SqliteReadException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    return points;
}


static int ReadEdgesCallback (void* data, int argc, char** argv, char **colNames) {
    (void) colNames;
    auto edges = static_cast<std::vector<Edge>*>(data);
    if (argc!= 3) {
        return 1;
    }
    int p1 = std::atoi(argv[1]) - 1;
    int p2 = std::atoi(argv[2]) - 1;
    if (p1 < 0 || p2 < 0) {
        return 1;
    }
    edges->push_back(Edge(p1, p2));
    return 0;
}

std::vector<Edge> SqliteBoneModelReader::ReadEdges() {
    if (!IsOpen()) {
        return std::vector<Edge>();
    }
    std::vector<Edge> edges;
    int rc = sqlite3_exec(_db, ReadEdgesSql, ReadEdgesCallback, &edges, nullptr);

    if (rc != SQLITE_OK) {
        time_t now = time(nullptr);
        throw SqliteReadException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    return edges;
}

Point SqliteBoneModelReader::ReadCenter() {
    std::vector<Point> points = ReadPoints();
    return _centerStrategy->CenterAlgorithm(points);
}