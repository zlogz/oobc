package magicbowen;

import org.testng.annotations.Test;
import static org.hamcrest.MatcherAssert.assertThat;
import static org.hamcrest.Matchers.*;

public class PositionTest {
    @Test()
    public void testEquals() {
        assertThat(new Position(0, 0), equalTo(new Position()));
    }

    @Test()
    public void testNotEquals() {
        assertThat(new Position(0, 0), not(equalTo(new Position(1, 0))));
    }

    @Test()
    public void testHashCode() {
        assertThat((new Position(1, 2)).hashCode(), equalTo((new Position(1, 2)).hashCode()));
    }

    @Test()
    public void testToString() {
        assertThat("Position(2, 3)", equalTo((new Position(2, 3)).toString()));
    }

    @Test()
    public void testRotateToLeft() {
        assertThat(new Position(-1, 0), equalTo((new Position(0, 1)).rotateToLeft()));
    }

    @Test()
    public void testRotateToRight() {
        assertThat(new Position(-1, 0), equalTo((new Position(0, -1)).rotateToRight()));
    }

    @Test()
    public void TestForward() {
        assertThat(new Position(2, 0), equalTo((new Position(1, 0)).forward(new Position(1, 0))));
    }

    @Test()
    public void TestBackward() {
        assertThat(new Position(1, 3), equalTo((new Position(2, 5)).backward(new Position(1, 2))));
    }
}
