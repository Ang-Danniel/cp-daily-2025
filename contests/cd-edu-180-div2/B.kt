import java.util.StringTokenizer
import java.io.PrintWriter

import kotlin.math.abs

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
    var t = readInt();
    var n: Int
    while (t-- > 0){
        n = readInt()
        var arr = readLine()!!.split(" ").map {i -> i.toInt()}.toIntArray()

        if (n == 2) {
            if ( abs(arr[0] - arr[1]) > 1 ) println(-1)
            else println(0);
            continue
        }
        
        var fi: Int
        var se: Int

        fi = arr[0]
        se = arr[1]

        var ans: Boolean?
        ans = null

        for (i in 2..n-1){
            var cur: Int = arr[i];
            if ((abs(fi - se) <= 1) or (abs(cur - se) <= 1)) {
                ans = true
                break
            }

            if (((fi < se) and (se > cur)) or ((fi > se) and (se < cur))){
                ans = false
            }
            fi = se
            se = cur
        }

        if (ans == null) println(-1)
        else if (ans == true) println(0)
        else println(1)
    }
}