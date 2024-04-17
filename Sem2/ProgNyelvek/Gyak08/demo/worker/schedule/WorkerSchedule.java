package worker.schedule;

import java.util.*;

public class WorkerSchedule {
    private HashMap<Integer, HashSet<String>> weekToWorkers;

    public WorkerSchedule() {
        weekToWorkers = new HashMap<Integer, HashSet<String>>();        
    }

    public void add(int week, HashSet<String> workers) {
        if (!weekToWorkers.containsKey(week)) {
            weekToWorkers.put(week, new HashSet<String>());
        }

        weekToWorkers.get(week).addAll(workers);
    }

    public void add(HashSet<Integer> weeks, ArrayList<String> workers) {
        HashSet<String> works = new HashSet<String>();
        for (String worker : workers)
            works.add(worker);

        for (Integer week : weeks)
            add(week, works);
    }

    public boolean isWorkingOnWeek(String worker, int week) {
        if (weekToWorkers.containsKey(week)) return false;
        return weekToWorkers.get(week).contains(worker);
    }

    public HashSet<Integer> getWorkWeeks(String worker) {
        HashSet<Integer> returned = new HashSet<Integer>();
        
        // Integer, HashSet kent fogjuk bejarni a weekToWorkers HashMape-et:
        for (Map.Entry<Integer, HashSet<String>> entry : weekToWorkers.entrySet()) {
            if (entry.getValue().contains(worker))
                returned.add(entry.getKey());
        }

        return returned;
    }
}
