import java.util.StringTokenizer
import java.io.PrintWriter

import kotlin.math.abs;

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
while(t-- > 0) solve()
}

fun solve(){
    var s: List<String> = readLine()!!.split(" ")
    var n: Int = s[0].length;

    var ans: Int = 0
    var cons: Boolean = false

    for (i in 0..n-1) {
        var dist = abs(s[0][i].code - s[1][i].code)
        
        if (cons) {
            if (s[0][i].code == 57 && s[1][i].code == 48) {
                ans++;
            } else {
                break;
            }
            continue
        }
        
        if (dist == 0) {
            ans+=2;
        } else if (dist == 1) {
            ans++;
            cons = true
        } else {
            break;
        }
    }

    println(ans);
}