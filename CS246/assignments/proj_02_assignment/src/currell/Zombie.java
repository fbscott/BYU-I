package currell;

import java.awt.*;

/**
 *  Zombies move from left to right and eat anything that's NOT a plant.
 * <p>
 * @author  Scott Currell
 * @version 1.0
 * @since   2020-01-15
 * @see Creature
 */
public class Zombie extends Creature implements Movable, Aggressor {

    public Zombie() {
        _health = 0;
    }

    public Boolean isAlive() { return _health == 0; }
    public Shape getShape() {
        return Shape.Square;
    }
    public Color getColor() {
        return new Color(0, 0, 255);
    }

    /**
     * If the creature we've encountered is NOT a plant, we'll eat it.
     * @param target The {@link Creature} we've encounterd.
     */
    public void attack(Creature target) {
        // Attack any creature that is NOT a plant.
        // Give the creature 10 damage.
        // Why doesn't this work?: if(!(target instanceof Plant)) { . . . }
        if(target instanceof Animal || target instanceof Wolf) { target.takeDamage(10); }
    }

    /**
     * Move the zombie left to right
     */
    public void move() {
        _location.x++;
    }
}
