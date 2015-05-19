public class Main {
    public static void main(String[] args) {
        Building bud1,bud2;
        bud1 = new Building();
        bud2 = new Building();
        Floor a,b,c;
        a= new Floor();
        b= new Floor();
        c= new Floor();
        Room x,y,z;
        x=new Room();
        y=new Room();
        z=new Room();
        bud1.AddFloors(a, b, c);
        bud2.AddFloors(a, b, c);
        bud1.GetFloors().get(0).AddRooms(x,y,z);
        System.out.println(bud1.GetFloors().get(0).LocationId.compareTo(bud2.GetFloors().get(0).LocationId));
    }
}