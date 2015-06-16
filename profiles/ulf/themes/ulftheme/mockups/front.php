<?php
$path_to_theme = "/profiles/ulf/themes/ulftheme/";
?>

<?php include('inc/head.inc') ?>
<title>Frontpage</title>
</head>
<body>
  <div class="page-wrapper js-page-wrapper">
    <div class="page-inner">
      <?php include('inc/header.inc') ?>
      <div class="layout-frontpage">
        <div class="layout-inner">
          <div class="layout-element-beta">
            <?php include('snippets/frontpage-blocks-promoted.inc') ?>
            <?php include('snippets/frontpage-blocks-primary-school.inc') ?>
            <?php include('snippets/frontpage-blocks-daycare.inc') ?>
            <?php include('snippets/frontpage-blocks-youth.inc') ?>
          </div>
          <div class="layout-element-gamma">
            <?php include('snippets/block-news.inc') ?>
          </div>
        </div>
      </div>
    </div>
  </div>
</body>
</html>