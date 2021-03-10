{}:
with import <nixpkgs> {};
stdenv.mkDerivation {
  name = "bs-optics";
  buildInputs = with pkgs; [
    docker-compose
    ocamlPackages.merlin
    ocamlPackages.ocaml-lsp
  ];
}
