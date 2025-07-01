import java.util.StringTokenizer
import java.io.PrintWriter

import kotlin.math.min
import java.util.*

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

fun main(){
    var t: Int = readInt()

    while(t-- > 0){
        solve()
    }
}

fun solve(){
    var n: Long = readLong()
    var m: Long = readLong()

    if (m < n || m > n * (n + 1L) / 2L) {
        println(-1)
        return
    }

    if (n == m) {
        println(1)
        for(i in 1L..n-1L){
            println("${i} ${i+1L}")
        }
        return
    }
    

    var v = ArrayList<Long>()
    var vis = MutableList<Boolean>(n.toInt() + 1) {index -> false}
    var maxx: Long
    var cum: Long = 0
    var cur: Long
    var q: Queue<Long> = LinkedList()
    for (i in n downTo 1L){
        maxx = m - cum - (i - 1L)
        cur = min(maxx, i)
        cum += cur
        v.add(cur)
        vis[cur.toInt()] = true
        if (!vis[i.toInt()]) q.add(i)
    }

    var front = v[0]
    println(front)
    for (i in 1..n.toInt() - 1){
        output {
            print(front)
            print(" ")
    
            if (v[i-1] == v[i]){
                front = q.peek()
                q.remove()
            } else front = v[i]
    
            print(front)
    
            println()
        }
    }

}

// 4 2 2 1
