<?php
$path_to_theme = "/profiles/ulf/themes/ulftheme/";
?>

<?php include('inc/head.inc') ?>
<title>ULF Course</title>
</head>
<body>
<div class="page-wrapper js-page-wrapper">
  <div class="page-inner">
    <?php include('inc/header.inc') ?>
    <div class="layout-alternative">
      <div class="layout-inner">
        <div class="layout-element-alpha">
          <div class="layout-element-inner">
            <?php include('snippets/page-course-content.inc') ?>
          </div>
          </div>
          <div class="layout-element-beta">
            <?php include('snippets/block-inline-useful.inc') ?>
            <?php include('snippets/block-inline-practical.inc') ?>
          </div>
          <div class="layout-element-gamma">
            <div class="layout-element-inner">
              <?php include('snippets/field-module-inspiration.inc') ?>
            </div>
          </div>
          <div class="layout-element-delta">
            <div class="layout-element-inner">
              <?php include('snippets/field-module-course-content.inc') ?>
            </div>
          </div>
          <div class="layout-element-epsilon">

          </div>
        </div>
      </div>
    </div>
  </div>
</div>
</body>
</html>