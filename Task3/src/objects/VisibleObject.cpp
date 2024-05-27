#include "../../inc/objects/VisibleObject.h"

VisibleObject::VisibleObject() {}

VisibleObject::~VisibleObject() {}

bool VisibleObject::IsVisible() const { return true; }

bool VisibleObject::IsComposite() const { return false; }
