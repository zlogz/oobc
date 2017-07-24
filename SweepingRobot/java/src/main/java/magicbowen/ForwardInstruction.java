package magicbowen;

/**
 * Created by wangbo on 2017/7/9.
 */
public class ForwardInstruction extends CommonInstruction {
    @Override
    protected Position changePosition(Position p, Direction d) {
        return p.forward(d.getUnit());
    }
}
