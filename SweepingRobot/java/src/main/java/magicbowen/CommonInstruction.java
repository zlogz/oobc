package magicbowen;

class CommonInstruction implements Instruction {
    public void run(Position p, Direction d) {
        position = changePosition(p, d);
        direction = changeDirection(d);
    }

    public Position getPosition() {
        return position;
    }

    public Direction getDirection() {
        return direction;
    }

    protected Position  changePosition(Position p, Direction d) { return p; }
    protected Direction changeDirection(Direction d) { return d; }

    protected Position position;
    protected Direction direction;
}
