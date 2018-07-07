uniform float time;
uniform vec2 resolution;

void main() {
    vec2 p = gl_FragCoord.xy / resolution.xy *  0.3;
    for(float i = 1.0; i < 8.0; i++){
        p.x += 0.3 / i * sin(i * 4.0 * p.y + time * 0.5 + cos((time / (100. * i)) * i));
        p.y += 0.4 / i * cos(i * 4.0 * p.x + time * 2.5 + sin((time / (200. * i)) * i));
    }
    float r = cos(p.x + p.y + 2.)*.5+.5;
    float g = sin(p.x + p.y + 1.)*.5+.5;
    float b = (sin(p.x + p.y + 1.) + cos(p.x + p.y + 1.))*0.5+ 0.5;
    vec3 col = (1.0 - mod(vec3(r, g, b) * 40.0, 1.0)) * 2.0;
    gl_FragColor = vec4(col, 1);
}
