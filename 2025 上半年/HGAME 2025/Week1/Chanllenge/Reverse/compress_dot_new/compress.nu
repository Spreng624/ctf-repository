def "into b" [] {
    let arg = $in;
    0..(( $arg|length ) - 1)|each {|i|$arg|bytes at $i..$i|into int}
};

def gss [] {
    match $in {{s:$s,w:$w} => [$s],{a:$a,b:$b,ss:$ss,w:$w} => $ss}
};

def gw [] {
    match $in {{s:$s,w:$w} => $w,{a:$a,b:$b,ss:$ss,w:$w} => $w}
};


def oi [v] {
    match $in {[] => [$v],[$h,..$t] => {if $v.w < $h.w {[$v,$h] ++ $t} else {[$h] ++ ($t|oi $v)}}}};

def h [] {match $in {[] => [],[$n] => $n,[$f,$sn,..$r] => {$r|oi {a:$f,b:$sn,ss:(($f|gss) ++ ($sn|gss)),w:(($f|gw) + ($sn|gw))}|h}}};

def gc [] {
    def t [nd, pth, cd] {
        match $nd {{s:$s,w:$_} => ($cd|append {s:$s,c:$pth}),{a:$a,b:$b,ss:$_,w:$_} => {t $b ($pth|append 1) (t $a ($pth|append 0) $cd)}}
    };
    t $in [] []|each {|e|{s:$e.s,cs:($e.c|each {|c|$c|into string}|str join)}}
};

def sk [] {
    match $in {null => null,{s:$s,w:$_} => {s:$s},{a:$a,b:$b,ss:$_,w:$_} => {a:($a|sk),b:($b|sk)}}
};
    
def bf [] {
    $in|into b|reduce -f (0..255|reduce -f [] {|i,a|$a|append 0}) {|b,a|$a|update $b (($a|get $b) + 1)}|enumerate|filter {|e|$e.item > 0}|each {|e|{s:$e.index,w:$e.item}}
};

def enc [cd] {
    $in|into b|each {|b|$cd|filter {|e|$e.s == $b}|first|get "cs"}|str join
};

def compress []: binary -> string {
    let t = $in|bf|h;
    [($t|sk|to json --raw), ($in|enc ($t|gc))]|str join "\n"
}

# source compress.nu
# open ./flag.txt --raw | into binary | compress | save enc.txt
