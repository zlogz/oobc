package magicbowen;

/**
 * Created by wangbo on 2017/7/9.
 */
public class RepeatInstruction implements Instruction{

    public RepeatInstruction(int count, Instruction instruction) {
        this.count = count;
        this.instruction = instruction;
    }

    public void run(Position p, Direction d) {
        Position position = p;
        Direction direction = d;
        for (int i = 0; i < count; i++) {
            instruction.run(position, direction);
            position = instruction.getPosition();
            direction = instruction.getDirection();
        }
    }

    public Position  getPosition() {
        return instruction.getPosition();
    }

    public Direction getDirection() {
        return instruction.getDirection();
    }

    private final int count;
    private final Instruction instruction;
}
