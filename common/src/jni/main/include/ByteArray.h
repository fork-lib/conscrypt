/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef BYTE_ARRAY_H_included
#define BYTE_ARRAY_H_included

// Returns true if the VM's JNI GetByteArrayElements method is likely to create a copy when invoked
// on an array of the provided size.
bool isGetByteArrayElementsLikelyToReturnACopy(size_t size) {
#if defined(ANDROID) && !defined(CONSCRYPT_OPENJDK)
    // ART's GetByteArrayElements creates copies only for arrays smaller than 12 kB.
    return size <= 12 * 1024;
#else
    (void) size;
    // On OpenJDK based VMs GetByteArrayElements appears to always create a copy.
    return true;
#endif
}

#endif  // BYTE_ARRAY_H_included
