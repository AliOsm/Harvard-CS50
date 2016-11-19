<form action="account.php" method="post">
    <fieldset>
        <div class="form-group">
            <input autocomplete="off" value="<?= $user["username"] ?>" autofocus class="form-control" name="username" placeholder="Username" type="text"/>
        </div>
        <div class="form-group">
            <input class="form-control" name="password" placeholder="New Password" type="password"/>
        </div>
        <div class="form-group">
            <input class="form-control" name="confirmation" placeholder="Confirmation" type="password"/>
        </div>
        <p>Leave password feilds empty if you don't want to change it.</p>
        <div class="form-group">
            <input class="form-control" name="opassword" placeholder="Old Password" type="password"/>
        </div>
        <p>We need your old password to change your information :)</p>
        <div class="form-group">
            <button class="btn btn-default" type="submit">
                Update
            </button>
        </div>
    </fieldset>
</form>