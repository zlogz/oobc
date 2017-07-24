package magicbowen;

import org.testng.annotations.BeforeMethod;
import org.testng.annotations.Test;
import static org.hamcrest.MatcherAssert.assertThat;  
import static org.hamcrest.Matchers.*;  

public class SweepingRobotTest {

    public void assertRobot(int x, int y, Direction direction) {
        assertThat(new Position(x, y), equalTo(robot.getPosition()));
        assertThat(direction, equalTo(robot.getDirection()));
    }

    @BeforeMethod()
    public void initRobot() {
        robot = new SweepingRobot();
    }

    @Test()
    public void testInitPosition() {
        assertRobot(0, 0, Direction.NORTH);
    }

    @Test()
    public void testMoveForward() {
        robot.execute(new ForwardInstruction());
        assertRobot(0, 1, Direction.NORTH);
    }

    @Test()
    public void testMoveBackward() {
        robot.execute(new BackwardInstruction());
        assertRobot(0, -1, Direction.NORTH);
    }

    @Test()
    public void testTurnLeft() {
        robot.execute(new TurnLeftInstruction());
        assertRobot(0, 0, Direction.WEST);
    }

    @Test()
    public void testTurnRight() {
        robot.execute(new TurnRightInstruction());
        assertRobot(0, 0, Direction.EAST);
    }

    @Test()
    public void testTurnRightAndForward() {
        robot.execute(new TurnRightInstruction());
        robot.execute(new ForwardInstruction());
        assertRobot(1, 0, Direction.EAST);
    }

    @Test()
    public void testFowardsNStep() {
        robot.execute(new ForwardsInstruction(10));
        assertRobot(0, 10, Direction.NORTH);
    }

    @Test()
    public void testRepeat() {
        robot.execute(new RepeatInstruction(10, new ForwardInstruction()));
        assertRobot(0, 10, Direction.NORTH);
    }

    @Test()
    public void testComposite() {
        CompositeInstruction instructions = new CompositeInstruction( new RepeatInstruction(2, new TurnRightInstruction())
                                                                    , new ForwardsInstruction(5));
        robot.execute(instructions);
        assertRobot(0, -5, Direction.SOUTH);
    }

    private SweepingRobot robot;
}