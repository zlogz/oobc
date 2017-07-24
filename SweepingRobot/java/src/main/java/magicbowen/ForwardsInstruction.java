package magicbowen;

/**
 * Created by wangbo on 2017/7/9.
 */
public class ForwardsInstruction implements Instruction {
    ForwardsInstruction(int steps) {
        instruction = new RepeatInstruction(steps, new ForwardInstruction());
    }

    public void run(Position p, Direction d) {
        instruction.run(p ,d);
    }

    public Position getPosition() {
        return instruction.getPosition();
    }

    public Direction getDirection() {
        return instruction.getDirection();
    }

    private final Instruction instruction;
}
