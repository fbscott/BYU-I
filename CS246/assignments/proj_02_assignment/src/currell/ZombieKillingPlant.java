package currell;

import java.awt.*;
import java.util.Random;

/**
 *  Kills zombies and spawns a new zombie-killing plant adjacent to the original.
 * <p>
 * @author  Scott Currell
 * @version 1.0
 * @since   2020-01-20
 * @see Creature
 */
public class ZombieKillingPlant extends Creature implements Aggressor, Spawner {

    private boolean _canSpawn = false;

    public ZombieKillingPlant() {
        _health = 1;
    }

    public Boolean isAlive() { return _health > 0; }
    public Shape getShape() {
        return Shape.Circle;
    }
    public Color getColor() {
        return new Color(255, 129, 0);
    }

    /**
     * If the creature we've encountered is a zombie, we'll eat it and spawn new
     * zombie-killing plants.
     * @param target The {@link Creature} we've encounterd.
     */
    public void attack(Creature target) {
        // Attack any zombie.
        // Give the zombie 5 damage.
        if(target instanceof Zombie) {

            target.takeDamage(5);
            _canSpawn = true;
        }
    }

    public Creature spawnNewCreature() {

        if (_canSpawn) {
            ZombieKillingPlant spawn = new ZombieKillingPlant();
            spawn.setLocation(new Point(this.getLocation()));
            spawn._location.y--;
            _canSpawn = !_canSpawn;
            return spawn;
        } else {
            return null;
        }
    }
}
