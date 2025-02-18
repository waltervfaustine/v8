// Copyright 2018 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef V8_OBJECTS_HEAP_OBJECT_INL_H_
#define V8_OBJECTS_HEAP_OBJECT_INL_H_

#include "src/objects/heap-object.h"

#include "src/heap/heap-write-barrier-inl.h"
// TODO(jkummerow): Get rid of this by moving NROSO::GetIsolate elsewhere.
#include "src/execution/isolate.h"

// Has to be the last include (doesn't have include guards):
#include "src/objects/object-macros.h"

namespace v8 {
namespace internal {

HeapObject::HeapObject(Address ptr, AllowInlineSmiStorage allow_smi)
    : Object(ptr) {
  SLOW_DCHECK(
      (allow_smi == AllowInlineSmiStorage::kAllowBeingASmi && IsSmi()) ||
      IsHeapObject());
}

// static
Heap* NeverReadOnlySpaceObject::GetHeap(const HeapObject object) {
  return GetHeapFromWritableObject(object);
}

// static
Isolate* NeverReadOnlySpaceObject::GetIsolate(const HeapObject object) {
  return GetIsolateFromWritableObject(object);
}

}  // namespace internal
}  // namespace v8

#include "src/objects/object-macros-undef.h"

#endif  // V8_OBJECTS_HEAP_OBJECT_INL_H_
