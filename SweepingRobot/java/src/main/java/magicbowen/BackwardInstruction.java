package magicbowen;

/**
 * Created by wangbo on 2017/7/9.
 */
public class BackwardInstruction extends CommonInstruction {
    @Override
    public Position changePosition(Position p, Direction d) {
        return p.backward(d.getUnit());
    }
}
