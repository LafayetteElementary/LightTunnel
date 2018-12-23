input.onButtonPressed(Button.A, function () {
    mode = (mode + 1) % 5
    basic.showString("" + mode)
    modifyMode(strip)
    modifyMode(strip2)
    modifyMode(strip3)
})
let mode = 0
let strip: neopixel.Strip = null
let strip2: neopixel.Strip = null
let strip3: neopixel.Strip = null
mode = 0
strip = neopixel.create(DigitalPin.P0, 150, NeoPixelMode.RGB)
strip2 = neopixel.create(DigitalPin.P1, 150, NeoPixelMode.RGB)
strip3 = neopixel.create(DigitalPin.P2, 150, NeoPixelMode.RGB)
initStrip(strip)
initStrip(strip2)
initStrip(strip3)
basic.showString("" + mode)
function initStrip(instance: neopixel.Strip) {
    instance.setBrightness(127)
    instance.showRainbow(1, 360)
}
function modifyMode(instance: neopixel.Strip) {
    if (mode == 0) {
        instance.clear()
        instance.showRainbow(1, 360)
    } else if (mode == 1) {
        instance.clear()
        for (let index = 0; index <= strip.length(); index = index + 2) {
            instance.setPixelColor(index, neopixel.colors(NeoPixelColors.White))
            instance.setPixelColor(index + 1, neopixel.colors(NeoPixelColors.Red))
        }
        instance.show()
    } else if (mode == 2) {
        instance.showColor(neopixel.colors(NeoPixelColors.White))
    } else if (mode == 3) {
        instance.showColor(neopixel.colors(NeoPixelColors.Red))
    } else if (mode == 4) {
        instance.showColor(neopixel.colors(NeoPixelColors.Blue))
    } else {
        instance.showColor(neopixel.colors(NeoPixelColors.Indigo))
    }
}
function rotateStrip(instance: neopixel.Strip) {
    instance.rotate(1)
    instance.show()
}
basic.forever(function () {
    if (mode == 0 || mode == 1) {
        rotateStrip(strip)
        rotateStrip(strip2)
        rotateStrip(strip3)
    }
    if (mode == 0) {
        basic.pause(20)
    }
    else {
        basic.pause(200)
    }
})

