
# Die Skip

A Geometry Dash mod made with [Geode](https://geode-sdk.org). When you die in a level, you skip to the next one instead of restarting.

## How it works

- Die in an official level (IDs 1 to 22, Stereo Madness to Fingerdash) and about one second later you are dropped into the next official level. After Fingerdash it loops back to Stereo Madness.
- Die in any other level (online or custom) and you go to Stereo Madness.
- Deaths from the anti-cheat spike and editor playtests are ignored.

## Known issues

- **QOLMod conflict.** The game crashed when this mod swapped levels while QOLMod (`thesillydoggo.qolmod`) was enabled. It went away with QOLMod disabled. The crash was inside QOLMod's collision code, so it is likely a stale-reference problem between the two mods. If you hit it, disable one of them.
- Only tested on Windows with Geometry Dash 2.2081 and Geode 5.9.

## Building

1. Install the [Geode CLI and SDK](https://docs.geode-sdk.org/getting-started/geode-cli). On Windows you also need Visual Studio's "Desktop development with C++" workload.
2. Run `geode sdk install-binaries` once if you have not already.
3. In this folder, run `geode build`. This builds the mod and installs it into your game.

## About this code

This mod was written with help from Claude, an AI assistant made by Anthropic. It is a small project (one file, `src/main.cpp`) and has had very little testing. It is not on the Geode index.

## License

MIT. See `LICENSE`.
