namespace HF10;

public class Gift {
    public TargetShot? targetShot = null;
    private Size size;

    public Gift(Size size) {
        this.size = size;
    }

    public int Value() {
        return Point() * size.Multi();
    }

    public virtual int Point() {
        return 0;
    }
}
