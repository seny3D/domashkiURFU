function time() {
    return new Date().getTime();
}

// var a = time();

// for (i=1; i <= 1000000000; i++){

// }

// var b = time();

// WSH.Echo((b-a) / 1000);


function bruteforce(text,pat) {
    var colvo = 10;
    var n = text.length;
    var m = pat.length;

    var cnt = 0;
    var arr = [];
    var start = time();

    for (var i = 0; i <= (n-m); i++) {
        var match = 1;
        for (var j = 0; j < m; j++) {
            if (text.charAt(i+j) != pat.charAt(j)) {
                match = 0;
                break;
            }
        }
        if (match == 1) {
            if (arr.length < colvo) {
                arr.push(i)
            }
            cnt += 1;
        
        }

    }
    var end = time();
    return ["Брутфорс", end-start, cnt, 0, " массив ", arr]; // время, количество вхождений, нет коллизий в бруте, первые 10 позиций
}

function linhash(text,pat) {
    var colvo = 10;
    var n = text.length;
    var m = pat.length;
    var cnt = 0;
    var arr = [];
    var colls = 0;
    var hashpat = 0;
    var hashtxt = 0;

    for (var j = 0; j <= m-1; j++) {
        hashpat += pat.charCodeAt(j);
    }
    for (var j = 0; j <= m - 1; j++) {
        hashtxt += text.charCodeAt(j);
    }
    var start = time();

    for (var i = 0; i <= (n - m); i++) {
        if (hashpat == hashtxt) {
            var match = 1;
            for (j = 0; j <= m-1; j++) {
                if (text.charAt(i + j) != pat.charAt(j)) {
                    match = 0;
                    // WSH.Echo(text.charAt(i + j), " ", pat.charAt(j))
                    break;
                }


            }
            if (match == 1) {
                cnt += 1;
                if (arr.length < colvo) {
                    arr.push(i);
                }
                
            }
            if (match == 0) {
                colls += 1;
            }
        }
        if (i < n - m ){
            hashtxt -= text.charCodeAt(i);
            hashtxt += text.charCodeAt(i+m);
        }
    }
    var end = time();
    return ["Линейный хеш",end-start,cnt,colls,"Массив",arr];

}

function quadrohash(text,pat) {
    var colvo = 10;
    var n = text.length;
    var m = pat.length;
    var cnt = 0;
    var arr = [];
    var colls = 0;
    var hashpat = 0;
    var hashtxt = 0;

    for (var j = 0; j <= m-1; j++) {
        var code = pat.charCodeAt(j);
        hashpat += (code*code);
        // WSH.Echo("хешпат", hashpat)

    }
    for (var j = 0; j <= m - 1; j++) {
        var cod = text.charCodeAt(j);
        hashtxt += (cod * cod);
        // WSH.Echo(hashtxt)
    }
    var start = time();

    for (var i = 0; i <= (n - m); i++) {
        if (hashpat == hashtxt) {
            var match = 1;
            for (j = 0; j <= m-1; j++) {
                if (text.charAt(i + j) != pat.charAt(j)) {
                    match = 0;

                    break;
                }
            }
            if (match == 1) {
                cnt += 1;
                if (arr.length < colvo) {
                    arr.push(i);
                }
            }
            if (match == 0) {
                colls += 1;
            }
        }
        if (i < n - m ){
            var old = text.charCodeAt(i);
            var nw = text.charCodeAt(i+m);
            hashtxt = hashtxt - (old*old) + (nw*nw);
            // hashtxt -= text.charCodeAt(i);
            // hashtxt += text.charCodeAt(i+m);
        }
    }
    var end = time();
    return ["квадро хеш",end-start,cnt,colls,"Массив",arr];
}

function rabinqarp(text,pat) {
    var p = 31; // множитель?
    var q = 1000000007;
    var colvo = 10;
    var n = text.length;
    var m = pat.length;
    var cnt = 0;
    var arr = [];
    var colls = 0;
    var hashpat = 0;
    var hashtxt = 0;
    
    var h = 1; // это будет множитель старшего символа
    for (var j = 0; j < m-1; j++) {
        h = (h * p) % q;
    }
    for (var j = 0; j <= m-1; j++) {
        hashpat = (p * hashpat + pat.charCodeAt(j)) % q;
        hashtxt = (p * hashtxt + text.charCodeAt(j)) % q;
    }
    var start = time();

    for (var i = 0; i <= (n-m); i++) {
        if (hashpat == hashtxt) {
            var match = 1;
            for (j = 0; j <= m-1; j++) {
                if (text[i+j] != pat[j]) {
                    match = 0;
                    break;
                }
            }
            if (match == 1) {
                cnt += 1;
                if (arr.length < colvo) {
                    arr.push(i);
                }
            }
            if (match == 0) {
                colls += 1;
            }
        }
        if (i < n -m) {
            hashtxt = (p * (hashtxt - text.charCodeAt(i) * h) + text.charCodeAt(i + m)) % q;
            if (hashtxt < 0) {
                hashtxt = hashtxt + q;
            }
        }
    }

    var end = time();
    return ["Рабин карп",end-start,cnt,colls,"Массив",arr];

}



function Node() {
    this.next = {};
    this.fail = null;
    this.out = []
}


function karasik(text, pats) {

    if (typeof pats == "string") {
        pats = [pats];
    }


    var colvo = 10;
    var n = text.length;
    var cnt = 0;
    var arr = [];

    var root = new Node();
    root.fail = root;

    for (var p = 0; p < pats.length; p++) {
        var pt = pats[p];
        var cur = root;

        for (var j = 0; j < pt.length; j++) {
            var chars = pt.charAt(j);
            if (!cur.next[chars]) {
                cur.next[chars] = new Node();
            }
            cur = cur.next[chars];
        }
        cur.out.push(pt.length) // получили короче длину слова, типо кот - 3, собака - 6, котик - 6. и короче по букве т пойдем
    }

    var queue = [];

    for (var chars in root.next) {
        if (root.next.hasOwnProperty(chars)) {
            // WSH.Echo(chars); // первые буквы. суффиксные ссылки тут
            var chid = root.next[chars];
            chid.fail = root;
            queue.push(chid);
        }
    }


    var head = 0;
    while (head < queue.length) {
        cur = queue[head++];
        for (var chars in cur.next) { // тут ищем суффиксные ссыкки для кажого символа, проверяем типо есть ли у узла переход по chars
            if (cur.next.hasOwnProperty(chars)) {
                var chid = cur.next[chars];
                var f = cur.fail;
                while (f != root && !f.next[chars]) {
                    f = f.fail;
                }
                if (f.next[chars]) {
                    chid.fail = f.next[chars];
                } 
                else {
                    chid.fail = root; // плохо все, нет такой ссылки
                }

                for (var k = 0; k < chid.fail.out.length; k++) {
                    
                    chid.out.push(chid.fail.out[k]); // "победа", наедстя слово "беда"
                }
                
                queue.push(chid);
            }
        }
    }

    var start = time();
    cur = root;
    for (var i = 0; i < n; i++) {
        chars = text.charAt(i);
        while (cur != root && !cur.next[chars]) {
            cur = cur.fail;
        }
        if (cur.next[chars]) {
            cur = cur.next[chars];
        }
        if (cur.out.length > 0) {
            for (var k = 0; k < cur.out.length; k++) {
                cnt += 1;
                if (arr.length < colvo) {
                    arr.push(i - cur.out[k] + 1);
                }
            }
        }
    }

    var end = time();

    return ['corasik', end - start, cnt, 0, "Массив", arr];   
}





// var fso = new ActiveXObject("Scripting.FileSystemObject");
// var files = fso.OpenTextFile("tom1234.txt", 1, false, 0).ReadAll();
// // Сбор словаря из текста
// var rawWords = files.split(/[^а-яА-ЯёЁa-zA-Z]+/);
// var dict = [];
// var seen = {};
// for (var i = 0; i < rawWords.length && dict.length < 50000; i++) {
//     var w = rawWords[i];
//     if (w.length > 3 && !seen[w]) {
//         seen[w] = true;
//         dict.push(w);
//     }
// }

// WSH.Echo("Слов в словаре: " + dict.length);
// WSH.Echo(karasik(files, dict));

// // Для сравнения: сколько времени займёт Рабин-Карп на тех же словах
// var rkStart = time();
// var rkTotalCnt = 0;
// for (var i = 0; i < dict.length; i++) {
//     rkTotalCnt += bruteforce(files, dict[i])[2];
// }
// WSH.Echo("Рабин-Карп на всех словах: " + (time() - rkStart) + " мс, найдено: " + rkTotalCnt);




var fso = new ActiveXObject("Scripting.FileSystemObject");
var files = fso.OpenTextFile("tom1234.txt", 1, false, 0).ReadAll();

var pattern = ["князь", "дом", "Андрей", "Мир"]; // "князь"; // Андрей Болконский";
// // var pattern = "аб";
// // var ch = "aaaaaaaaaaaaaaaaббaaaaaaaaaaaaaaaaaaaaaaaa";

// // for (var i = 0; i < 250000; i++) {
// //     files += ch;
// // }

// WSH.Echo(bruteforce(files, pattern));
// WSH.Echo(linhash(files, pattern));
// WSH.Echo(quadrohash(files, pattern));
// WSH.Echo(rabinqarp(files, pattern));
WSH.Echo(karasik(files,pattern));


// var nestedText = "абабабабабабабабабаб";
// var nestedPats = ["а", "аб", "ба", "аба", "баб", "абаб", "баба", "абабабаб"];
// WSH.Echo(karasik(nestedText, nestedPats));

// var bombText = new Array(100001).join("а"); // строка из 100 000 букв 'а'
// var bombPats = [];
// var curPat = "";
// for (var i = 0; i < 500; i++) {
//     curPat += "а";
//     bombPats.push(curPat);
// }

// WSH.Echo("Бомба-тест:");
// WSH.Echo(karasik(bombText, bombPats));

// var failText = new Array(50000).join("аааааааааб") + "ааааааааав";
// var failPats = [
//     "аааааааааа", // 10 букв 'а' (почти совпадает, но в тексте 9 'а' и 'б')
//     "ааааааааабв",
//     "аааааб",
//     "б"
// ];
// WSH.Echo("Тест на откаты:");
// WSH.Echo(karasik(failText, failPats));

// Проверка на коллизию со встроенными свойствами Object.prototype!
// var protoText = "constructor toString valueOf hasOwnProperty";
// var protoPats = ["constructor", "toString", "valueOf", "hasOwnProperty"];
// WSH.Echo("Тест на свойства прототипа:");
// WSH.Echo(karasik(protoText, protoPats));
