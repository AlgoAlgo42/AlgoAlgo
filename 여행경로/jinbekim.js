function solution(tickets) {
	var answer = [];
	const DEP = 0,
		ARR = 1;
	DFS(tickets, 'ICN', ['ICN']);
	return answer.sort()[0];
	function DFS(tickets, depature, route) {
		if (tickets.length == 0) {
			answer.push(route);
		}
		for (var i in tickets) {
			if (tickets[i][0] == depature) {
				let tmp = tickets.slice();
				tmp.splice(i, 1);
				let tmp2 = route.slice();
				tmp2.push(tickets[i][ARR]);
				DFS(tmp, tickets[i][ARR], tmp2);
			}
		}
	}
}

console.log(
	solution([
		['ICN', 'SFO'],
		['ICN', 'ATL'],
		['SFO', 'ATL'],
		['ATL', 'ICN'],
		['ATL', 'SFO'],
	])
);
