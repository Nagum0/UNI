public class Chameleon extends Animal {
    private boolean dependantEyeMovement;
    
    public Chameleon(String color, boolean eyeMovement) {
        super(color);
        this.dependantEyeMovement = dependantEyeMovement;
    }

    @Override
    public String toString() {
        return super.toString() + " eye movement: " + dependantEyeMovement;
    }
}