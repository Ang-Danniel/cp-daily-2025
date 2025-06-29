import java.util.StringTokenizer
import java.io.PrintWriter

import java.util.*

import kotlin.math.max

@JvmField val INPUT = System.`in`
@JvmField val OUTPUT = System.out
@JvmField val _reader = INPUT.bufferedReader()
fun readLine(): String? = _reader.readLine()
fun readLn() = _reader.readLine()!!
@JvmField var _tokenizer: StringTokenizer = StringTokenizer("")
fun read(): String {
while (_tokenizer.hasMoreTokens().not()) _tokenizer = StringTokenizer(_reader.readLine() ?: return "", " ")
return _tokenizer.nextToken()
}
fun readInt() = read().toInt()
fun readDouble() = read().toDouble()
fun readLong() = read().toLong()
fun readStrings(n: Int) = List(n) { read() }
fun readLines(n: Int) = List(n) { readLn() }
fun readInts(n: Int) = List(n) { read().toInt() }
fun readIntArray(n: Int) = IntArray(n) { read().toInt() }
fun readDoubles(n: Int) = List(n) { read().toDouble() }
fun readDoubleArray(n: Int) = DoubleArray(n) { read().toDouble() }
fun readLongs(n: Int) = List(n) { read().toLong() }
fun readLongArray(n: Int) = LongArray(n) { read().toLong() }
@JvmField val _writer = PrintWriter(OUTPUT, false)
inline fun output(block: PrintWriter.() -> Unit) { _writer.apply(block).flush() }

var adj: MutableMap<Int, MutableList<Int>> = mutableMapOf<Int, MutableList<Int>>()
var vis = MutableList(1) {index -> false};

fun main(){
    var t: Int = readInt()
    while (t-- > 0) {
        solve()
    }
}

fun solve(){
    var n: Int = readInt()
    adj = mutableMapOf<Int, MutableList<Int>>();
    vis = MutableList(n+1) {index -> false}

    for (i in 1..n-1){
        var input = readLine()!!.split(" ").map {it.toInt()}.toIntArray()

        if (adj[input[0]] == null) adj[input[0]] = mutableListOf<Int>()
        if (adj[input[1]] == null) adj[input[1]] = mutableListOf<Int>()

        adj[input[0]]!!.add(input[1])
        adj[input[1]]!!.add(input[0])
    }

    if (n <= 2) {
        println("NO")
        return
    }

    if (n == 3) {
        var a: Int = adj[1]!!.count()
        var b: Int = adj[2]!!.count()
        var c: Int = adj[3]!!.count()
        var ctr: Int
        println("YES")
        if (a == 2) {
            println("2 1")
            println("1 3")
        }
        else if (b == 2) {
            println("3 2")
            println("2 1")
        }
        else {
            println("1 3")
            println("3 2")
        }
        return
    }

    val q: Queue<Int> = LinkedList()
    q.add(1)
    vis[1] = true
    var exist = false
    var ctr: Int = 0

    while (!q.isEmpty()){
        val front: Int = q.peek()
        q.remove()
        var count: Int = 0
        for (i in adj[front]!!){    
            if (vis[i]) continue
            vis[i] = true
            q.add(i)
            count++
        }   
        // println("${front} ${count}")
        if (front == 1 && count == 2) {
            ctr = 1
            exist = true
            break
        } 

        if (front != 1 && count == 1) {
            ctr = front
            exist = true
            break
        }
    }

    if (!exist) {
        println("NO")
        return
    }

    vis = MutableList(n+1) {index -> false}
    println("YES")
    println("${ctr} ${adj[ctr]!![0]}")
    println("${adj[ctr]!![1]} ${ctr}")

    vis[ctr] = true
    dfs(adj[ctr]!![0], true)
    dfs(adj[ctr]!![1], false)
}

fun dfs(index: Int, dir: Boolean) {
    vis[index] = true
    for (i in adj[index]!!){
        if (vis[i]) continue
        if (!dir) println("${index} ${i}")
        else println("${i} ${index}")
        dfs(i, !dir)
    }
}