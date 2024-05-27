#include "../../inc/objects/InvisibleObject.h"

InvisibleObject::InvisibleObject() {}

InvisibleObject::~InvisibleObject() {}

bool InvisibleObject::IsVisible() const { return false; }

bool InvisibleObject::IsComposite() const { return false; }