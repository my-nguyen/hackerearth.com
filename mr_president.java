// part of Code Monk (Revision) challenge on 9/9/2015
// gave up because this is the 5th problem and altogether it has taken 1.5 days
// and i had other things to do. only finished reading input, storing input in a
// data structure and displaying input
// need algorithm to go thru the data structure to make the calculation required
// Mr. President
// You have recently started playing a brand new computer game called Mr.
// President. The game is about ruling a country, building infrastructures and
// developing it.
// Your country consists of N cities and M bidirectional roads connecting them.
// Each road has assigned a cost of its maintenance. The greatest achievement in
// the game is called Great administrator and it is given to a player who manage
// to have all cities in the country connected by roads in such a way that it is
// possible to travel between any two cities and that the sum of maintenance
// costs of these roads is not greater than K.
// This is very hard to accomplish, but you are very close to do it. More
// precisely, you have just discovered a new method of transforming standard
// roads into super roads, with cost of maintenance just 1, due to their extreme
// durability.
// The bad news is that it is very expensive to transform a standard road into a
// super road, but you are so excited that you are going to do it anyway.
// In addition, because you have a lot of other expenses, you also want to first
// demolish as many roads as possible in order to safe some money on their
// maintenance first and then start working on getting the achievement. You can
// demolish any road in the country and that operation does not cost you anything.
// Because you want to spend the absolutely minimum money in order to get the
// achievement, you are interested in the smallest number of transformations of
// standard roads into super roads in such a way that you can do that.
// Input format
// In the first line there are 3 integers N, M and K denoting the number of
// cities in the country, the number of roads in it and the desired sum of costs
// of maintenance. M lines describing these roads follow. In each of them there
// are 3 integers A, B and C, where A and B denote the endpoints of the road
// while C denotes the cost of its maintenance.
// Output
// In a single line, output the minimum number of roads which need to be
// transformed in order to get the achievement. If you cannot do it no matter
// what, output -1.
// Constraints
// 2 = N, M = 10^6
// 0 = K = 10^18
// 1 = A, B = N and A != B
// 1 = C = 10^6
// Sample Input(Plaintext Link)
// 3 3 25
// 1 2 10
// 2 3 20
// 3 1 30
// Sample Output(Plaintext Link)
// 1
// Explanation
// You can transform to super a road either the road between cities 1 and 2 or
// the road between cities 2 and 3 in order to produce the desired road network
// of costs respectively 21 and 11. Doing that will cost you one transformation
// and it is optimal in this case.
//
import java.util.*;

// no built-in java Pair class
class connection_t
{
  public connection_t(int k, int c)
  {
    key = k;
    cost = c;
  }
  int key;
  int cost;
}

class mr_president
{
  private static void new_connection(Map<Integer, ArrayList<connection_t>> map,
    int cityA, int cityB, int cost)
  {
    ArrayList<connection_t> list;
    // if key exists, then get the list object from key
    if (map.containsKey(cityA))
      list = map.get(cityA);
    // otherwise, create a list and add a new entry <key, list> into map
    else
    {
      list = new ArrayList<connection_t>();
      map.put(cityA, list);
    }
    // add new connection from cityA to cityB together with cost
    list.add(new connection_t(cityB, cost));
  }

  private static void new_entry(Map<Integer, ArrayList<connection_t>> map,
    int cityA, int cityB, int cost)
  {
    new_connection(map, cityA, cityB, cost);
    new_connection(map, cityB, cityA, cost);
  }

  private static void input(Map<Integer, ArrayList<connection_t>> map, int desired_cost)
  {
    Scanner scanner = new Scanner(System.in);
    int city_count = scanner.nextInt();
    int road_count = scanner.nextInt();
    desired_cost = scanner.nextInt();

    for (int i = 0; i < road_count; i++)
    {
      int cityA = scanner.nextInt();
      int cityB = scanner.nextInt();
      int cost = scanner.nextInt();

      new_entry(map, cityA, cityB, cost);
    }
  }

  public static void main(String[] args)
  {
    Map<Integer, ArrayList<connection_t>> map = new HashMap<Integer, ArrayList<connection_t>>();
    int desired_cost = 0;
    input(map, desired_cost);

    for (Map.Entry<Integer, ArrayList<connection_t>> entry : map.entrySet())
    {
      for (connection_t connection : entry.getValue())
        System.out.println("city: " + entry.getKey() + ", other: "
          + connection.key + ", cost: " + connection.cost);
    }
  }
}
