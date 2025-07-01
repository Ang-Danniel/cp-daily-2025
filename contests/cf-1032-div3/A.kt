import java.util.StringTokenizer
import java.io.PrintWriter

import kotlin.math.min
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
    while(t-- > 0){
        solve()
    }
}

fun solve(){
    var n: Int
    var s: Int

    n = readInt()
    s = readInt()

    var minn: Int = Int.MAX_VALUE
    var maxx: Int = 0
    var input: Int
    for (i in 1..n){
        input = readInt()
        minn = min(minn, input)
        maxx = max(maxx, input)
    }
    output{
        if (s <= minn) {
            println(maxx - minn + (minn - s))
        }else if(s >= maxx){
            println(maxx - minn + (s - maxx))
        }else{
            println(maxx - minn + min(s - minn, maxx -s))
        }
    }
}