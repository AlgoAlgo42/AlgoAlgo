const input = require('fs')
	.readFileSync('/dev/stdin', 'utf8')
	.toString()
	.trim()
	.split('\n');

function getMinimum(arr, visited) {
	let min = Infinity;
	let idx = -1;
	for (let i = 0; i < arr.length; ++i) {
		if (!visited[i] && arr[i] < min) {
			min = arr[i];
			idx = i;
		}
	}
	return idx;
}

function dijkstra(graph, startNode, n) {
	const dist = new Array(n + 1).fill(Infinity);
	const visited = new Array(n + 1).fill(false);
	dist[startNode] = 0;
	for (let val of graph[startNode]) {
		dist[val[0]] = val[1];
	}
	let index = getMinimum(dist, visited);
	while (index !== -1) {
		visited[index] = true;
		if (graph[index] !== undefined) {
			for (let val of graph[index]) {
				if (dist[val[0]] > dist[index] + val[1]) {
					dist[val[0]] = dist[index] + val[1];
				}
			}
		}
		index = getMinimum(dist, visited);
	}
	for (let i = 1; i <= n; ++i) {
		if (dist[i] === Infinity) console.log('INF');
		else console.log(dist[i]);
	}
}
function init() {
	const [n, m] = input[0].split(' ').map(Number);
	const startNode = input[1].split(' ').map(Number)[0];
	const graph = {};
	for (let i = 0; i < m; ++i) {
		const [u, v, w] = input[i + 2].split(' ').map(Number);
		graph[u] = graph[u] || [];
		graph[u].push([v, w]);
	}
	dijkstra(graph, startNode, n);
}

init();
