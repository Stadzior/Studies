import java.util.ArrayList;
import java.util.concurrent.atomic.AtomicInteger;

public class Floor extends Location {
    private static final AtomicInteger count = new AtomicInteger(-1);
    private ArrayList<Room> rooms;
    public Floor() {
        rooms= new ArrayList<Room>();
        this.LocationId=new Id(0,count.incrementAndGet(),0);
    }
    public ArrayList<Room> GetRooms()
    {
        return rooms;
    }
    public void AddRooms(Room...args)
    {
        for(int i=0;i<args.length;i++)
        {
            rooms.add(args[i]);
        }
    }
    @Override
    void Describe(){
        System.out.println("Pietro: "+this.LocationId.FloorId);
    }
}