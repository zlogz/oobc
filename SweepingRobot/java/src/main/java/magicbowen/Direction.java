package magicbowen;

import java.util.HashMap;

class Direction {
    private static final HashMap<Position, String> DIRECTION_NAMES;
    static {
        DIRECTION_NAMES = new HashMap<Position, String>();
        DIRECTION_NAMES.put(new Position(0, 1),  "north");
        DIRECTION_NAMES.put(new Position(1, 0),  "east");
        DIRECTION_NAMES.put(new Position(0, -1), "south");
        DIRECTION_NAMES.put(new Position(-1, 0), "west");
    }

    static final Direction NORTH = new Direction(new Position(0, 1));
    static final Direction EAST  = new Direction(new Position(1, 0));
    static final Direction SOUTH = new Direction(new Position(0, -1));
    static final Direction WEST  = new Direction(new Position(-1, 0));

    private Direction(Position unit) {
        this.unit = unit;
    }

    public Direction leftSide() {
        return new Direction(unit.rotateToLeft());
    }

    public Direction rightSide() {
        return new Direction(unit.rotateToRight());
    }

    public Position getUnit() {
        return unit;
    }

    @Override
    public boolean equals(Object other) {
        if (this == other) return true;
        if (! (other instanceof Direction)) return false;
        return this.unit.equals(((Direction)other).unit);
    }

    @Override
    public int hashCode() {
        return this.unit.hashCode();
    }

    @Override
    public String toString() {
        return DIRECTION_NAMES.get(unit);
    }

    private final Position unit;
}
