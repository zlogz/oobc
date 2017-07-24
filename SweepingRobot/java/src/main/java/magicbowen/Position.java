package magicbowen;

/**
 * Created by wangbo on 2017/7/8.
 */
class Position {
    public Position()
    {
        x = 0;
        y = 0;
    }

    public Position(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public Position rotateToLeft() {
        return new Position(-y, x);
    }

    public Position rotateToRight() {
        return new Position(y, -x);
    }

    public Position forward(Position unit) {
        return new Position(x + unit.x, y + unit.y);
    }

    public Position backward(Position unit) {
        return new Position(x - unit.x, y - unit.y);
    }

    @Override
    public boolean equals(Object other) {
        if (this == other) return true;
        if (!(other instanceof  Position)) return false;
        Position otherPosition = (Position)other;
        return (x == otherPosition.x) && (y == otherPosition.y);
    }

    @Override
    public int hashCode() {
        int result = 17;
        result = 31 * result + x;
        result = 31 * result + y;
        return result;
    }

    @Override
    public String toString() {
        return String.format("Position(%d, %d)", x, y);
    }

    private final int x;
    private final int y;

}
