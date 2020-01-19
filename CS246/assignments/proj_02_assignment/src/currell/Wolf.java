package currell;

import java.awt.*;
import java.util.Random;

/**
 *  Wolves move at random at first, then chase their prey.
 * <p>
 * @author  Scott Currell
 * @version 1.0
 * @since   2020-01-15
 * @see Creature
 */
public class Wolf extends Creature implements Movable, Aggressor, Aware, Spawner {

    Random _rand;
    int _preferredDirection;
    boolean _canSpawn = false;

    public Wolf() {
        _rand = new Random();
        _health = 1;
        _preferredDirection = _rand.nextInt(4);
    }

    public Boolean isAlive() { return _health > 0; }
    public Shape getShape() {
        return Shape.Square;
    }
    public Color getColor() {
        return new Color(128, 128, 128);
    }

    public void senseNeighbors(Creature above, Creature below, Creature left, Creature right) {
        if (_preferredDirection == 0) { // right
            if (right instanceof Animal) {
                _preferredDirection = 0;
            } else if (above instanceof Animal) {
                _preferredDirection = 3;
            } else if (below instanceof Animal) {
                _preferredDirection = 2;
            } else if (left instanceof Animal) {
                _preferredDirection = 1;
            }
        } else if (_preferredDirection == 1) { // left
            if (left instanceof Animal) {
                _preferredDirection = 1;
            } else if (above instanceof Animal) {
                _preferredDirection = 3;
            } else if (right instanceof Animal) {
                _preferredDirection = 0;
            } else if (below instanceof Animal) {
                _preferredDirection = 2;
            }
        } else if (_preferredDirection == 2) { // below
            if (below instanceof Animal) {
                _preferredDirection = 2;
            } else if (above instanceof Animal) {
                _preferredDirection = 3;
            } else if (right instanceof Animal) {
                _preferredDirection = 0;
            } else if (left instanceof Animal) {
                _preferredDirection = 1;
            }
        } else if (_preferredDirection == 3) { // above
            if (above instanceof Animal) {
                _preferredDirection = 3;
            } else if (right instanceof Animal) {
                _preferredDirection = 0;
            } else if (below instanceof Animal) {
                _preferredDirection = 2;
            } else if (left instanceof Animal) {
                _preferredDirection = 1;
            }
        }
    }

    public void move() {

        // Choose a random direction each time move() is called.
        switch(_preferredDirection) {
            case 0:
                _location.x++; // right
                break;
            case 1:
                _location.x--; // left
                break;
            case 2:
                _location.y++; // below
                break;
            case 3:
                _location.y--; // above
                break;
            default:
                break;
        }
    }

    /**
     * If the creature we've encountered is NOT a plant, we'll eat it.
     * @param target The {@link Creature} we've encounterd.
     */
    public void attack(Creature target) {
        // Attack any animal.
        // Give the animal 5 damage.
        if(target instanceof Animal) {

            target.takeDamage(5);
            _canSpawn = true;
        }
    }

    public Creature spawnNewCreature() {

        if (_canSpawn) {
            Wolf spawn = new Wolf();
            spawn.setLocation(new Point(this.getLocation()));
            spawn._location.x--;
            _canSpawn = !_canSpawn;
            return spawn;
        } else {
            return null;
        }
    }
}
