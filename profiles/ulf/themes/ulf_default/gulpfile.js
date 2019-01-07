// Plugins.
var gulp = require('gulp');
var jshint = require('gulp-jshint');
var stylish = require('jshint-stylish');
var sass = require('gulp-sass');
var sourcemaps = require('gulp-sourcemaps');
var concat = require('gulp-concat');
var uglify = require('gulp-uglify');
var ngAnnotate = require('gulp-ng-annotate');
var rename = require('gulp-rename');
var compass = require('gulp-compass');

// We only want to process our own non-processed JavaScript files.
var jsPath = ['./scripts/*.js', '!./js/*.min.*'];
var sassPath = './sass/**/*.scss';
var phpPath = './**/*.php'; //could also be twig files
var buildDir = './js';

/**
 * Run Javascript through JSHint.
 */

gulp.task('jshint', function(done) {
  gulp.src(jsPath)
    .pipe(jshint())
    .pipe(jshint.reporter(stylish));
  done();
});

/**
 * Run Javascript through JSHint.
 */

gulp.task('uglify', function(done) {
  gulp.src(jsPath)
    .pipe(uglify())
    .pipe(rename({
      suffix: '-min'
    }))
    .pipe(gulp.dest('./scripts/min'))
  done();
});

/**
 * Process SCSS using libsass
 */
gulp.task('sass', function (done) {
  gulp.src(sassPath)
    .pipe(sass({
      outputStyle: 'compressed',
      includePaths: [
        './node_modules/compass-mixins/lib'
      ]
    }).on('error', sass.logError))
    .pipe(gulp.dest('./css'));
  done();
});

/**
 * Watch files for changes and run tasks.
 */

gulp.task('watch', function() {
  gulp.watch(jsPath, gulp.series('jshint', 'uglify'));
  gulp.watch(sassPath, gulp.series('sass'));
});

/**
 * Watch javascript files for changes.
 */

gulp.task('js-watch', function() {
  gulp.watch(jsPath, gulp.series('jshint'));
});

/**
 * Build single app.js file.
 */
gulp.task('buildJs', function (done) {
  gulp.src(jsPath)
    .pipe(sourcemaps.init())
    .pipe(uglify())
    .pipe(sourcemaps.write('/maps'))
    .pipe(rename({extname: ".min.js"}))
    .pipe(gulp.dest(buildDir))
  done();
});

/**
 * Build single app.js file.
 */
gulp.task('assetsJs', function (done) {
  gulp.src(jsAssets)
    .pipe(concat('assets.js'))
    .pipe(rename({extname: ".min.js"}))
    .pipe(gulp.dest(buildDir))
  done();
});

/**
 * Use compass
 */
gulp.task('compass', function(done) {
  gulp.src(sassPath)
    .pipe(compass({
      css: 'css',
      sass: 'scss',
      image: 'img'
    }))
    .pipe(minifycss())
    .pipe(gulp.dest('html/css'));
  done();
});

// Tasks to compile sass and watch js file.
gulp.task('default', gulp.parallel('sass', 'watch', 'uglify'));
gulp.task('build', gulp.parallel('buildJs', 'sass', 'uglify'));
