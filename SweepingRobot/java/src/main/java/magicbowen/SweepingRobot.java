package magicbowen;


public class SweepingRobot {
    SweepingRobot() {
        position = new Position();
        direction = Direction.NORTH;
    }

    public Position getPosition() {
        return position;
    }

    public Direction getDirection() {
        return direction;
    }

    public void execute(Instruction instruction) {
        instruction.run(position, direction);
        position = instruction.getPosition();
        direction = instruction.getDirection();
    }

    @Override
    public String toString() {
        return String.format("SweepingRobot(%s, %s)", position, direction);
    }

    private Position  position;
    private Direction direction;
}
