/**
 * This file is part of the "dim" project
 *   Copyright (c) 2020 Christian Parpart <christian@parpart.family>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <ostream>
#include <linear_algebra>
#include "support.h"

#include <catch2/catch.hpp>

TEST_CASE("multiplication")
{
    SECTION("vector * vector")
    {
        auto static const v1 = ivec<3>{5, 2, 3};
        auto static const v2 = ivec<3>{1, 2, 5};
        auto static const v3 = v1 * v2;
        auto static const expected = 24;
        REQUIRE(v3 == expected);
    }

    SECTION("scalar * vector")
    {
        auto static const v1 = ivec<3>{5, 2, 3};
        auto static const s1 = 4;
        auto static const v2 = s1 * v1;
        auto static const expected = ivec<3>{20, 8, 12};
        REQUIRE(v2 == expected);
    }

    SECTION("vector * scalar")
    {
        auto static const v1 = ivec<3>{5, 2, 3};
        auto static const s1 = 4;
        auto static const v2 = v1 * s1;
        auto static const expected = ivec<3>{20, 8, 12};
        REQUIRE(v2 == expected);
    }

    SECTION("scalar * matrix")
    {
        auto static const m1 = imat<2, 3>{1, 2, 3, 4, 5, 6};
        auto static const s1 = 2;
        auto static m2 = s1 * m1;
        auto static expected = imat<2, 3>{2, 4, 6, 8, 10, 12};
        REQUIRE(m2 == expected);
    }

    SECTION("matrix * scalar")
    {
        auto static const m1 = imat<2, 3>{1, 2, 3, 4, 5, 6};
        auto static const s1 = 2;
        auto static m2 = m1 * s1;
        auto static expected = imat<2, 3>{2, 4, 6, 8, 10, 12};
        REQUIRE(m2 == expected);
    }

    // TODO: matrix * matrix
    // TODO: matrix * vector
    // TODO: vector * matrix (where left hand side is treated as transposed vector, i.e. 1-row matrix)
}