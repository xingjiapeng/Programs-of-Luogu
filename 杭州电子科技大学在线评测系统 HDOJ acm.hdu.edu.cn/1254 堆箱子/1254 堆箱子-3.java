//Create by zwd
// http://acm.hdu.edu.cn/discuss/problem/post/reply.php?postid=21314&messageid=1&deep=0
import java.util.ArrayDeque;
import java.util.HashSet;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;

class Status
{
	int x, y, startX, startY;
	Status parent;
	int step;

	public Status(int x, int y, int startX, int startY)
	{
		this.x = x;
		this.y = y;
		this.startX = startX;
		this.startY = startY;
	}

	@Override
	public int hashCode()
	{
		final int prime = 31;
		int result = 1;
		result = prime * result + startX;
		result = prime * result + startY;
		result = prime * result + x;
		result = prime * result + y;
		return result;
	}

	@Override
	public boolean equals(Object obj)
	{
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Status other = (Status) obj;
		if (startX != other.startX)
			return false;
		if (startY != other.startY)
			return false;
		if (x != other.x)
			return false;
		if (y != other.y)
			return false;
		return true;
	}

	@Override
	public String toString()
	{
		return "Status [x=" + x + ", y=" + y + ", startX=" + startX + ", startY=" + startY + "]";
	}

}

class StatusofPorter
{
	int x, y;
	StatusofPorter parent;

	public StatusofPorter(int x, int y)
	{
		this.x = x;
		this.y = y;
	}

	@Override
	public int hashCode()
	{
		final int prime = 31;
		int result = 1;
		result = prime * result + x;
		result = prime * result + y;
		return result;
	}

	@Override
	public boolean equals(Object obj)
	{
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		StatusofPorter other = (StatusofPorter) obj;
		if (x != other.x)
			return false;
		if (y != other.y)
			return false;
		return true;
	}

}

class StatusofPorterRepeatChecker
{
	Set<StatusofPorter> set;

	public StatusofPorterRepeatChecker(int xCount, int yCount)
	{
		set = new HashSet<StatusofPorter>();
	}

	public void add(StatusofPorter status)
	{
		set.add(status);
	}

	public boolean isExists(StatusofPorter status)
	{
		return set.contains(status);
	}
}

class StatusRepeatChecker
{

	Set<Status> set;

	public StatusRepeatChecker(int xCount, int yCount)
	{
		set = new HashSet<Status>();
	}

	public void add(Status status)
	{
		set.add(status);
	}

	public boolean isExists(Status status)
	{
		return set.contains(status);
	}

}

class Maze
{
	private int[][] map;
	private int xCount;
	private int yCount;

	public Maze(int xCount, int yCount, Scanner scan)
	{
		this.xCount = xCount;
		this.yCount = yCount;
		map = new int[xCount][yCount];
		for (int y = 0; y < yCount; y++)
		{
			for (int x = 0; x < xCount; x++)
			{
				map[x][y] = scan.nextInt();
			}
		}
		endX = getEndX();
		endY = getEndY();
	}

	int endX;
	int endY;

	public int getStartX()
	{
		for (int x = 0; x < xCount; x++)
			for (int y = 0; y < yCount; y++)
				if (map[x][y] == 2)
					return x;
		return -1;
	}

	public int getStartY()
	{
		for (int x = 0; x < xCount; x++)
			for (int y = 0; y < yCount; y++)
				if (map[x][y] == 2)
					return y;
		return -1;
	}

	public int getEndX()
	{
		for (int x = 0; x < xCount; x++)
			for (int y = 0; y < yCount; y++)
				if (map[x][y] == 3)
					return x;
		return -1;
	}

	public int getEndY()
	{
		for (int x = 0; x < xCount; x++)
			for (int y = 0; y < yCount; y++)
				if (map[x][y] == 3)
					return y;
		return -1;
	}

	public int getStartXofporter()
	{
		for (int x = 0; x < xCount; x++)
			for (int y = 0; y < yCount; y++)
				if (map[x][y] == 4)
				{
					return x;
				}
		return -1;
	}

	public int getStartYofporter()
	{
		for (int x = 0; x < xCount; x++)
			for (int y = 0; y < yCount; y++)
				if (map[x][y] == 4)
				{
					return y;
				}
		return -1;
	}

	public boolean isIllegal(int x, int y)
	{
		if (x < 0 || x >= xCount)
			return false;
		if (y < 0 || y >= yCount)
			return false;
		if (map[x][y] == 1)
			return false;
		return true;
	}

	public boolean isIllegal0(int x, int y, int x0, int y0)
	{
		if (x < 0 || x >= xCount)
			return false;
		if (y < 0 || y >= yCount)
			return false;
		if (map[x][y] == 1)
			return false;
		if (x == x0 && y == y0)
			return false;
		return true;
	}
}

public class Main
{

	private static Queue<Status> queue;
	private static Queue<StatusofPorter> queue0;
	private static StatusRepeatChecker checker;
	private static StatusofPorterRepeatChecker checker0;
	private static Maze maze;

	private static int xCount, yCount, timeCount;

	private static boolean isEnd(Status status)
	{
		return (status.x == maze.endX && status.y == maze.endY);
	}

	private static boolean isEnd0(StatusofPorter status, int x, int y)
	{
		return (status.x == x && status.y == y);
	}

	private static void expand0(StatusofPorter currentStatus0, int x0, int y0)
	{
		int dx[] = { 0, 1, 0, -1 };
		int dy[] = { 1, 0, -1, 0 };
		for (int dir = 0; dir < 4; dir++)
		{
			StatusofPorter nextStatus0 = new StatusofPorter(currentStatus0.x + dx[dir], currentStatus0.y + dy[dir]);

			if (!maze.isIllegal0(nextStatus0.x, nextStatus0.y, x0, y0))
				continue;
			if (checker0.isExists(nextStatus0))
				continue;
			nextStatus0.parent = currentStatus0;
			queue0.add(nextStatus0);
			checker0.add(nextStatus0);
		}
	}

	static boolean bfsx0(int x, int y, int x0, int y0, int startX, int startY)
	{
		queue0 = new ArrayDeque<StatusofPorter>();
		checker0 = new StatusofPorterRepeatChecker(xCount, yCount);
		StatusofPorter initStatusofPorter = new StatusofPorter(startX, startY);
		queue0.add(initStatusofPorter);
		checker0.add(initStatusofPorter);
		boolean bool = false;
		StatusofPorter endStatus0 = null;
		while (!queue0.isEmpty())
		{
			StatusofPorter currentStatus0 = queue0.poll();
			// 判断是否结束
			if (isEnd0(currentStatus0, x, y))
			{
				endStatus0 = currentStatus0;
				bool = true;
				break;
			}
			expand0(currentStatus0, x0, y0);
		}
		return bool;
	}

	private static void expand(Status currentStatus)
	{
		int dx[] = { 0, 1, 0, -1 };
		int dy[] = { 1, 0, -1, 0 };
		for (int dir = 0; dir < 4; dir++)
		{
			Status nextStatus = new Status(currentStatus.x + dx[dir], currentStatus.y + dy[dir], -1, -1);
			if (!maze.isIllegal(nextStatus.x, nextStatus.y))
				continue;
			if (dir == 0)
			{

				if (!bfsx0(currentStatus.x, currentStatus.y - 1, currentStatus.x, currentStatus.y, currentStatus.startX, currentStatus.startY))
				{
					continue;
				}
				nextStatus.startX = currentStatus.x;
				nextStatus.startY = currentStatus.y;
			}
			if (dir == 1)
			{
				if (!bfsx0(currentStatus.x - 1, currentStatus.y, currentStatus.x, currentStatus.y, currentStatus.startX, currentStatus.startY))
				{
					continue;
				}
				nextStatus.startX = currentStatus.x;
				nextStatus.startY = currentStatus.y;
			}
			if (dir == 2)
			{
				if (!bfsx0(currentStatus.x, currentStatus.y + 1, currentStatus.x, currentStatus.y, currentStatus.startX, currentStatus.startY))
				{
					continue;
				}
				nextStatus.startX = currentStatus.x;
				nextStatus.startY = currentStatus.y;
			}
			if (dir == 3)
			{
				if (!bfsx0(currentStatus.x + 1, currentStatus.y, currentStatus.x, currentStatus.y, currentStatus.startX, currentStatus.startY))
				{
					continue;
				}
				nextStatus.startX = currentStatus.x;
				nextStatus.startY = currentStatus.y;
			}

			if (checker.isExists(nextStatus))
				continue;

			nextStatus.parent = currentStatus;
			nextStatus.step = currentStatus.step + 1;

			queue.add(nextStatus);
			checker.add(nextStatus);
		}
	}

	private static void print(Status status)
	{
		if (status == null)
			return;
		print(status.parent);
		System.out.println(status.x + " " + status.y);
	}

	public static void bfs()
	{
		Status initStatus = new Status(maze.getStartX(), maze.getStartY(), maze.getStartXofporter(), maze.getStartYofporter());
		initStatus.step = 0;
		queue.add(initStatus);
		checker.add(initStatus);
		Status endStatus = null;

		while (!queue.isEmpty())
		{
			Status currentStatus = queue.poll();
			if (isEnd(currentStatus))
			{
				endStatus = currentStatus;
				break;
			}

			expand(currentStatus);

		}

		if (endStatus != null)
		{
			System.out.println(endStatus.step);
		}
		else
		{
			System.out.println(-1);
		}
	}

	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);
		int t = scan.nextInt();
		for (int i = 0; i < t; i++)
		{
			yCount = scan.nextInt();
			xCount = scan.nextInt();
			queue = new ArrayDeque<Status>();
			checker = new StatusRepeatChecker(xCount, yCount);
			maze = new Maze(xCount, yCount, scan);
			bfs();
		}
	}
}
