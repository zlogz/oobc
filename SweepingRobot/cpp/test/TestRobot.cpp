#include "gtest/gtest.h"
#include "coordinate/Direction.h"
#include "command_utils.h"
#include "Robot.h"

///////////////////////////////////////////////////////
struct RobotTest : public testing::Test
{
protected:
    bool isRobotAt(const Position& position, const Direction& direction) const
    {
        return (position == robot.getPosition()) &&
               (direction == robot.getDirection());
    }

    Robot robot;
};

//////////////////////////////////////////////////////
#define ASSERT_ROBOT_AT(x, y ,direction)        \
ASSERT_TRUE(isRobotAt(Position(x, y), direction))

//////////////////////////////////////////////////////
TEST_F(RobotTest, should_at_0_0_north_when_init_a_new_robot)
{
    ASSERT_ROBOT_AT(0, 0, __north);
}

//////////////////////////////////////////////////////
TEST_F(RobotTest, should_at_0_0_west_when_a_new_robot_turn_left)
{
    robot.execute(__turn_left);
    ASSERT_ROBOT_AT(0, 0, __west);
}

//////////////////////////////////////////////////////
TEST_F(RobotTest, should_at_0_0_east_when_a_new_robot_turn_right)
{
    robot.execute(__turn_right);
    ASSERT_ROBOT_AT(0, 0, __east);
}

//////////////////////////////////////////////////////
TEST_F(RobotTest, should_at_0_1_north_when_a_new_robot_forward_one_step)
{
    robot.execute(__forward);
    ASSERT_ROBOT_AT(0, 1, __north);
}

//////////////////////////////////////////////////////
TEST_F(RobotTest, should_at_0_neg_1_north_when_a_new_robot_backward_one_step)
{
    robot.execute(__backward);
    ASSERT_ROBOT_AT(0, -1, __north);
}

//////////////////////////////////////////////////////
TEST_F(RobotTest, should_at_0_0_south_when_a_new_robot_turn_round)
{
    robot.execute(__turn_round);
    ASSERT_ROBOT_AT(0, 0, __south);
}

//////////////////////////////////////////////////////
TEST_F(RobotTest, should_at_0_10_north_when_a_new_robot_forward_ten_step)
{
    robot.execute(__forwards(10));
    ASSERT_ROBOT_AT(0, 10, __north);
}

//////////////////////////////////////////////////////
TEST_F(RobotTest, should_at_0_neg_10_north_when_a_new_robot_backward_ten_step)
{
    robot.execute(__backwards(10));
    ASSERT_ROBOT_AT(0, -10, __north);
}

//////////////////////////////////////////////////////
TEST_F(RobotTest, should_at_0_neg_6_north_when_a_new_robot_repeat_3_times_of_backward_double_steps)
{
    robot.execute(__repeat(3, __backwards(2)));
    ASSERT_ROBOT_AT(0, -6, __north);
}

//////////////////////////////////////////////////////
TEST_F(RobotTest, should_at_neg_1_neg_1_north_when_a_new_robot_execute_sequential_commands)
{
    robot.execute(__commands(__forward, __turn_left, __forward, __turn_right, __repeat(4, __turn_left)));
    ASSERT_ROBOT_AT(-1, 1, __north);
}
