package magicbowen;

import java.util.ArrayList;
import java.util.Vector;

/**
 * Created by wangbo on 2017/7/9.
 */
public class CompositeInstruction implements Instruction {

    public CompositeInstruction(Instruction... instructions) {
        this.instructions = instructions;
    }

    public void run(Position p, Direction d) {
        Position position = p;
        Direction direction = d;
        for (Instruction instruction : instructions) {
            instruction.run(position, direction);
            position = instruction.getPosition();
            direction = instruction.getDirection();
        }
    }

    public Position getPosition() {
        if(instructions == null) throw new NullPointerException();
        return instructions[instructions.length - 1].getPosition();
    }

    public Direction getDirection() {
        if(instructions == null) throw new NullPointerException();
        return instructions[instructions.length - 1].getDirection();
    }

    private Instruction[] instructions;
}
