package magicbowen;

/**
 * Created by wangbo on 2017/7/9.
 */
public class TurnLeftInstruction extends CommonInstruction {
    public Direction changeDirection(Direction d) {
        return d.leftSide();
    }
}
