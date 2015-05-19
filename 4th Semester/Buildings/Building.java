import java.util.ArrayList;
import java.util.concurrent.atomic.AtomicInteger;

public class Building extends Location {
    private static final AtomicInteger count = new AtomicInteger(-1);
    private ArrayList<Floor> floors;
    public Building()
    {
        floors=new ArrayList<Floor>();
        this.LocationId=new Id(count.incrementAndGet(),0,0);
    }
    public ArrayList<Floor> GetFloors()
    {
        return floors;
    }
    public void AddFloors(Floor...args)
    {
        for(int i = 0;i<args.length;i++)
        {
            floors.add(args[i]);
        }
    }
    @Override
    void Describe() {
        System.out.println("Budynek: "+this.LocationId.BuildingId);
    }
}