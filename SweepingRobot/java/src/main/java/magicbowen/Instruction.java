package magicbowen;

public interface Instruction {
    void run(Position p, Direction d);
    Position  getPosition();
    Direction getDirection();
}

