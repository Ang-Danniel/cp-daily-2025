import java.util.StringTokenizer
import java.io.PrintWriter

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

fun main(){
    var t: Int = readInt()

    while (t-- > 0){
        solve()
    }
}

fun solve() {
    var a: Int = readInt()
    var x: Int = readInt()

    var b: Int = readInt()
    var y: Int = readInt()
    
    var c: Int = readInt()
    var z: Int = readInt()

    if (a + b + c == max(x, max(y, z)) && x == y && y == z){
        println("YES")
        return
    } 

    if (x + y + z == max(a, max(b, c)) && a == b && b == c){
        println("YES")
        return
    } 

    if (x == y + z && b == c && a + b == x){
        println("YES")
        return
    }

    if (a == b + c && y == z && x + y == a){
        println("YES")
        return
    }

    println("NO")
}