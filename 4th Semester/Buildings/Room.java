import java.util.concurrent.atomic.AtomicInteger;

public class Room extends Location {
    private static final AtomicInteger count = new AtomicInteger(-1);
    public Room() {
        this.LocationId=new Id(0,0,count.incrementAndGet());
    }
    @Override
    void Describe(){
        System.out.println("Pokoj: "+this.LocationId.RoomId);
    }
}