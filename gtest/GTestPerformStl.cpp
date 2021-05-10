#include "stl.h"
#include "gtest/gtest.h"

namespace 
{
    class TestPerformStl : public testing::Test
    {
        void SetUp() override
        {};

        void TearDown() override
        {};
    };
}

TEST_F(TestPerformStl, TEST_PERFORMSTL)
{
    PerformStl demo;
    ASSERT_EQ(STL_OK, demo.PerformVector());
}
