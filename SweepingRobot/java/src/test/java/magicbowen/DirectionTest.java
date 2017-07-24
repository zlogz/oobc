package magicbowen;

import org.testng.annotations.Test;
import static org.hamcrest.MatcherAssert.assertThat;
import static org.hamcrest.Matchers.*;

public class DirectionTest {

    @Test()
    public void testUnit() {
        assertThat(new Position(0, 1), equalTo(Direction.NORTH.getUnit()));
    }

    @Test()
    public void testEquals() {
        assertThat(Direction.NORTH, equalTo(Direction.NORTH));
    }

    @Test()
    public void testNotEquals() {
        assertThat(Direction.NORTH, not(equalTo(Direction.EAST)));
    }

    @Test()
    public void testHashCode() {
        assertThat(Direction.EAST.hashCode(), equalTo(Direction.EAST.hashCode()));
    }

    @Test()
    public void testToString() {
        assertThat("south", equalTo(Direction.SOUTH.toString()));
    }

    @Test()
    public void testLeftSide() {
        assertThat(Direction.WEST, equalTo(Direction.NORTH.leftSide()));
    }
    @Test()
    public void testRightSide() {
        assertThat(Direction.WEST, equalTo(Direction.SOUTH.rightSide()));
    }
}
