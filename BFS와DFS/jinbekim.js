const input = require('fs')
	.readFileSync('/dev/stdin')
	.toString()
	.trim()
	.split('\n');
const [N, M, V] = input[0].split(' ').map(Number);
const graph = {};

for (let i = 0; i < M; ++i) {
	const [v1, v2] = input[1 + i].split(' ').map(Number);
	graph[v1] = graph[v1] || [];
	graph[v2] = graph[v2] || [];
	graph[v1].push(v2);
	graph[v2].push(v1);
}
for (let vertax in graph) {
	graph[vertax].sort((a, b) => a - b);
}

const dfs = function (graph, start) {
	const visited = new Array(N).fill(false);
	const stack = [];
	let result = '';
	result += start;
	visited[result] = true;
	if (graph[start]) {
		for (let i = graph[start].length - 1; i >= 0; --i) {
			stack.push(graph[start][i]);
		}
		while (stack.length) {
			const node = stack.pop();
			if (visited[node]) continue;
			visited[node] = true;
			result += ' ' + node;
			for (let i = graph[node].length - 1; i >= 0; --i) {
				stack.push(graph[node][i]);
			}
		}
	}
	console.log(result);
};

const bfs = function (graph, start) {
	const visited = new Array(N).fill(false);
	const queue = [];
	let result = '';
	result += start;
	visited[start] = true;
	if (graph[start]) {
		for (let node of graph[start]) {
			queue.push(node);
		}
		while (queue.length) {
			const node = queue.shift();
			if (visited[node]) continue;
			visited[node] = true;
			result += ' ' + node;
			for (let ver of graph[node]) {
				queue.push(ver);
			}
		}
	}
	console.log(result);
};

dfs(graph, V);
bfs(graph, V);
