std::vector<int> getRes(std::priority_queue<std::pair<int, int>, 
                                            std::vector<std::pair<int, int>>, 
                                            std::greater<std::pair<int, int>>>& q) {
  std::vector<int> res;
  while (!q.empty()) {
    auto job = q.top();
    q.pop();
    res.push_back(job.second);
  }
  return res;
}

std::vector<int> jobScheduling(std::vector<int> requestTime, std::vector<int> jobProcess, int timeFromStart) {
  std::priority_queue<std::pair<int, int>,
                      std::vector<std::pair<int, int>>, 
                      std::greater<std::pair<int, int>>> q;
  int finishTime = -1;
  int curTime = 0;
  int i = 0;

  while (i < requestTime.size() || !q.empty()) {
    if (finishTime == -1) {
      finishTime = jobProcess[i] + requestTime[i];
      i++;
    }
    else {
      auto request = i < requestTime[i] ? std::make_pair(requestTime[i], jobProcess[i]) : std::make_pair(INT_MAX, INT_MAX);
      if (request.first <= finishTime || q.empty()) {
        curTime = request.first;
        if (curTime > timeFromStart) {
          return getRes(q);
        }
        q.push(std::make_pair(request.second, i++));
      }
      else {
        curTime = finishTime;
        auto job = q.top();
        finishTime += job.first;
        if (curTime >= timeFromStart) {
          return getRes(q);
        }
        q.pop();
      }
    }
  }
  return {1};
}
