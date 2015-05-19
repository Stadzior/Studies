public class Id implements Comparable<Id>{
    int BuildingId;
    int FloorId;
    int RoomId;

    public Id(int BuildingId, int FloorId, int RoomId) {
        this.BuildingId=BuildingId;
        this.FloorId=FloorId;
        this.RoomId=RoomId;
    }

    @Override
    public int compareTo(Id o) {
        if(this.BuildingId==o.BuildingId)
        {
            if(this.FloorId==o.FloorId)
            {
                if(this.RoomId==o.RoomId)
                {
                    return 0;
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                return -2;
            }
        }
        else
        {
            return -3;
        }
    }
}