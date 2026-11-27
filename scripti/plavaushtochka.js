var ini = WScript.StdIn;
var out = WScript.StdOut;


function lft(st, ln) {
    while (st.length < ln) {
        st = "0" + st;
    }

    return st
}

function rght(st, ln) {
    while (st.length < ln) {
        st = st + "0";
    }
    return st;
}

function to2(a, ln) {
    var res = a.toString(2);
    return lft(res,ln);
}


function toIEEE754(a) {
    a = a.replace(/^\s+|\s+$/g, "").split(",").join(".");

    var numa = parseFloat(a);
    if (isNaN(numa)) return to2(2143289344,32);

    var s = (numa < 0 || (numa === 0 && 1 / numa === -Infinity)) ? "1" : "0";

    if (numa === 0) {
        return s + to2(0,31);
    }

    var numabs = Math.abs(numa);

    var mx = (2 - Math.pow(2, -23)) * Math.pow(2,127); // число из солодушкина

    if (!isFinite(numabs) || numabs > mx) {
        return s + to2(2139095040, 31);
    }

    var cel = Math.floor(numabs);
    var drob = numabs - cel;
    var bincel = cel.toString(2);
    var bindrob = "";

    for (var i = 0; i < 155; i++) {
        drob *= 2;
        if (drob >= 1) {
            bindrob += "1";
            drob -= 1;
        }
        else {
            bindrob += "0";
        }
    }

    var p = 0; // нормализцаия, реализовать потом, не забудь дундук
    var mantisa = "";
    if (cel > 0) {
        p = bincel.length - 1;
        mantisa = rght(bincel.substring(1) + bindrob, 23).substring(0,23);
    }
    else {
        var pervy = bindrob.indexOf("1");
        if (pervy === -1) {
            return s + to2(0,31);
        }
        p = -(pervy + 1);
        mantisa = rght(bindrob.substring(pervy+1),23).substring(0,23);
    }

    var pkav = p + 127;// p' из описания задачи
    if (pkav <= 0) {
        // mantisa = rght(bindrob.substring(126), 23).substring(0, 23);
        // return s + to2(0,8) + mantisa;
        return s + to2(0,31);
    }

    return s + to2(pkav,8) + mantisa;
}


function fromIEEE754(a) {
    var s = (a.charAt(0) === "1") ? -1 : 1;
    var pkav = parseInt(a.substring(1,9), 2);
    var mantisastr = a.substring(9,32);

    if (pkav === 255) {
        if (mantisastr.indexOf("1") !== -1) {
            return NaN;
        }
        return s * Infinity;
    }
    if (pkav === 0) {
        return s * 0;
    }

    var p = pkav - 127;
    var mantisa = "1" + mantisastr;
    var res = 0;

    for (var i = 0; i < mantisa.length; i++) {
        if (mantisa.charAt(i) == "1") {
            res += Math.pow(2, p - i);
        }
    }
    return s * res;
}


WScript.Echo(fromIEEE754(toIEEE754("0")))
WScript.Echo(fromIEEE754(toIEEE754("-0")))
WScript.Echo(fromIEEE754(toIEEE754("12,5")));
WScript.Echo(fromIEEE754(toIEEE754("1,1754944e-38")))




