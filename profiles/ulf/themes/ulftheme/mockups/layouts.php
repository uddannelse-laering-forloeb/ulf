<?php
$path_to_theme = "/profiles/ulf/themes/ulftheme/";
?>

<?php include('inc/head.inc') ?>
<title>ULF layouts</title>
</head>
<body>
  <div class="page-wrapper js-page-wrapper">
    <div class="page-inner">
      <?php include('inc/header.inc') ?>
      <div class="layout-frontpage">
        <div class="layout-inner">
          <h1 style="border-bottom: 1px dashed gray; margin-right: .5em; margin-bottom: 1em; margin-left: .5em; padding-bottom: .5em;">Frontpage</h1>
          <div class="layout-element-alpha">
            <div class="layout-element-inner">
              Alpha (empty for now)
            </div>
          </div>
          <div class="layout-element-beta">
            <div class="layout-element-inner">
              <?php include('snippets/frontpage-blocks-promoted.inc') ?>
              <?php include('snippets/frontpage-blocks-primary-school.inc') ?>
              <?php include('snippets/frontpage-blocks-daycare.inc') ?>
              <?php include('snippets/frontpage-blocks-youth.inc') ?>
            </div>
          </div>
          <div class="layout-element-gamma">
            <div class="layout-element-inner">
              <?php include('snippets/block-news.inc') ?>
            </div>
          </div>
        </div>
      </div>
      <div class="layout-search">
        <div class="layout-inner">
          <h1 style="border-bottom: 1px dashed gray; margin-right: .5em; margin-bottom: 1em; margin-left: .5em; padding-bottom: .5em;">Search results (list)</h1>
          <div class="layout-element-alpha">
            <div class="layout-element-inner">
              <?php include('snippets/search-module.inc') ?>
              <?php include('snippets/search-facets-content.inc') ?>
              <?php include('snippets/search-module-results-list.inc') ?>
            </div>
          </div>
          <div class="layout-element-beta">
            <div class="layout-element-inner">
              <?php include('snippets/search-facets.inc') ?>
            </div>
          </div>
        </div>
      </div>
      <div class="layout-search">
        <div class="layout-inner">
          <h1 style="border-bottom: 1px dashed gray; margin-right: .5em; margin-bottom: 1em; margin-left: .5em; padding-bottom: .5em;">Search results (gallery)</h1>
          <div class="layout-element-alpha">
            <div class="layout-element-inner">
              <?php include('snippets/search-module.inc') ?>
              <?php include('snippets/search-facets-content.inc') ?>
              <?php include('snippets/search-module-results-thumbs.inc') ?>
            </div>
          </div>
          <div class="layout-element-beta">
            <div class="layout-element-inner">
              <?php include('snippets/search-facets.inc') ?>
            </div>
          </div>
        </div>
      </div>
      <div class="layout-alternative">
        <div class="layout-inner">
          <h1 style="border-bottom: 1px dashed gray; margin-right: .5em; margin-bottom: 1em; margin-left: .5em; padding-bottom: .5em;">Course</h1>
          <div class="layout-element-alpha">
            <div class="layout-element-inner">
              <?php include('snippets/page-course-content.inc') ?>
            </div>
          </div>
          <div class="layout-element-beta">
            <div class="layout-element-inner">
              <?php include('snippets/block-inline-useful.inc') ?>
              <?php include('snippets/block-inline-practical.inc') ?>
            </div>
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
        </div>
      </div>
      <div class="layout-alternative">
        <div class="layout-inner">
          <h1 style="border-bottom: 1px dashed gray; margin-right: .5em; margin-bottom: 1em; margin-left: .5em; padding-bottom: .5em;">Static page</h1>
          <div class="layout-element-alpha">
            <div class="layout-element-inner">
              <?php include('snippets/tabs.inc') ?>
              <?php include('snippets/page-content.inc') ?>
            </div>
          </div>
          <div class="layout-element-beta">
            <div class="layout-element-inner">
              <?php include('snippets/block-news.inc') ?>
            </div>
          </div>
        </div>
      </div>
      <div class="layout-alternative">
        <div class="layout-inner">
          <h1 style="border-bottom: 1px dashed gray; margin-right: .5em; margin-bottom: 1em; margin-left: .5em; padding-bottom: .5em;">News page</h1>
          <div class="layout-element-alpha">
            <div class="layout-element-inner">
              <?php include('snippets/page-news-content.inc') ?>
            </div>
          </div>
          <div class="layout-element-beta">
            <div class="layout-element-inner">
              <?php include('snippets/block-news.inc') ?>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
</body>
</html>
