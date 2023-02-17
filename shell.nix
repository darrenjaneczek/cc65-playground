with (import <nixpkgs> {});
mkShell {
    shellHook=''
        echo Adding $buildInputs/share/cc65/include to the CC65_INC include path
        export CC65_INC=$buildInputs/share/cc65/include
    '';
    buildInputs = [
        cc65
    ];
}

